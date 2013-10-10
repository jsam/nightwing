Xephyr +extension RANDR -ac -screen 1440x900 -br -reset -terminate 2> /dev/null :1 & (sleep 1; export DISPLAY=:1; xterm & ./bin/nightwing)
