FILEPATH=""
if [ $# -eq 1 ]; then
    FILEPATH=$1
fi

./blk_writer $FILEPATH &

sleep 0.3 

sudo echo c > /proc/sysrq-trigger
