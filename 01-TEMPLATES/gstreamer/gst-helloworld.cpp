#include <cstdio>
#include <unistd.h>
#include <sys/time.h>
#include <cstring>

#define RETURN_EMSG_IF(exp, r, msg)     do {\
    if ((exp)) {\
        fprintf(stderr, "ERROR: %s", (msg));\
        return (r);\
    }\
} while(0)

extern "C" {
#include <gst/gst.h>
}

const char *const VIDEO_SRC  = (const char *)"videotestsrc";
const char *const VIDEO_ENC  = (const char *)"x264enc";
const char *const VIDEO_DEC  = (const char *)"avdec_h264";
const char *const VIDEO_SINK = (const char *)"autovideosink";

int fps = 0;

static GstPadProbeReturn
cb_have_data(GstPad *pad, GstPadProbeInfo *info, gpointer user_data)
{
    GstBuffer *buffer = gst_pad_probe_info_get_buffer(info);
    printf("Buffer size = %lu\n", gst_buffer_get_size(buffer));

    ++fps;

    return GST_PAD_PROBE_OK;
}

static void print_fps(int sig)
{
    printf("FPS = %d\n", fps);
    fps = 0;
}

int main(int argc, char *argv[])
{
    struct sigaction sa;    
    struct itimerval it;

    gst_init(&argc, &argv);
    
    GMainLoop  *mainLoop  = g_main_loop_new(nullptr, FALSE);
    GstElement *pipeline  = gst_pipeline_new("template");
    GstElement *videoSrc  = gst_element_factory_make(VIDEO_SRC,  nullptr);
    GstElement *videoEnc  = gst_element_factory_make(VIDEO_ENC,  nullptr);
    GstElement *videoDec  = gst_element_factory_make(VIDEO_DEC,  nullptr);
    GstElement *videoSink = gst_element_factory_make(VIDEO_SINK, nullptr);
    GstPad     *fpsPad    = nullptr;
    
    it.it_interval.tv_sec  = 1;
    it.it_interval.tv_usec = 0;
    it.it_value.tv_sec     = 1; 
    it.it_value.tv_usec    = 0; 

    memset(&sa, 0, sizeof (sa));
    sa.sa_handler = &print_fps;
    sa.sa_flags   = SA_RESTART;
    sigaction(SIGALRM, &sa, nullptr);

    setitimer(ITIMER_REAL, &it, nullptr);
    
    RETURN_EMSG_IF((!videoSrc || !videoEnc || !videoDec || !videoSink || !pipeline), -1, 
        "Could not create one or all plugins\n");
    
    gst_bin_add_many(GST_BIN(pipeline), videoSrc, videoEnc, videoDec, videoSink, nullptr);
    
    RETURN_EMSG_IF(!gst_element_link_many(videoSrc, videoEnc, videoDec, videoSink, nullptr), -1,
        "Could not link plugins.\n");
    
    fpsPad = gst_element_get_static_pad(videoEnc, "src");
    RETURN_EMSG_IF(!fpsPad, -1, "Could not get pad.\n");
    
    gst_pad_add_probe(fpsPad, GST_PAD_PROBE_TYPE_BUFFER, cb_have_data, nullptr, nullptr);

    printf("Now playing...\n");
    
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    
    g_main_loop_run(mainLoop);

    gst_element_set_state(pipeline, GST_STATE_NULL);

    return 0;
}