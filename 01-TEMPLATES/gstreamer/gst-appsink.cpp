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
const char *const VIDEO_SINK = (const char *)"autovideosink";

int fps = 0;

static GstPadProbeReturn
cb_have_data(GstPad *pad, GstPadProbeInfo *info, gpointer user_data)
{
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
    gboolean error = 0;    

    struct sigaction sa;    
    struct itimerval it;

    gst_init(&argc, &argv);
    
    GMainLoop  *mainLoop = g_main_loop_new(nullptr, FALSE);
    GstElement *pipeline = gst_pipeline_new("template");
    GstElement *src      = gst_element_factory_make(VIDEO_SRC,  nullptr);
    GstElement *appsink  = gst_element_factory_make("appsink",  nullptr);
    GstElement *appsrc   = gst_element_factory_make("appsrc",   nullptr);
    GstElement *sink     = gst_element_factory_make(VIDEO_SINK, nullptr);
    GstPad     *fpsPad   = nullptr;
    GstCaps    *videoCap = nullptr;
    
    it.it_interval.tv_sec  = 1;
    it.it_interval.tv_usec = 0;
    it.it_value.tv_sec     = 1; 
    it.it_value.tv_usec    = 0; 

    memset(&sa, 0, sizeof (sa));
    sa.sa_handler = &print_fps;
    sa.sa_flags   = SA_RESTART;
    sigaction(SIGALRM, &sa, nullptr);

    setitimer(ITIMER_REAL, &it, nullptr);
    
    RETURN_EMSG_IF((!src || appsink || appsrc || !sink || !pipeline), -1, 
        "Could not create one or all plugins\n");
    
    gst_bin_add_many(GST_BIN(pipeline), src, appsink, appsrc, sink, nullptr);
    
    error = gst_element_link(src, appsink);
    RETURN_EMSG_IF(error, error, "Could not link video src to appsink");

    error = gst_element_link(appsrc, sink);
    RETURN_EMSG_IF(error, error, "Could not link appsrc video sink");
    
    fpsPad = gst_element_get_static_pad(src, "src");
    RETURN_EMSG_IF(!fpsPad, -1, "Could not get pad.\n");
    
    videoCap = gst_pad_get_current_caps(fpsPad);
    
    gst_pad_add_probe(fpsPad, GST_PAD_PROBE_TYPE_BUFFER, cb_have_data, nullptr, nullptr);

    printf("Now playing...\n");
    
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    
    g_main_loop_run(mainLoop);

    gst_element_set_state(pipeline, GST_STATE_NULL);

    return 0;
}