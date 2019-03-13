#!/bin/bash

killall server

./_build/server &
sleep 1
./_build/client
