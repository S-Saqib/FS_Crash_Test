FILEPATH=""
if [ $# -eq 1 ]; then
    FILEPATH=$1
fi

./blk_writer_with_sleep $FILEPATH &

sleep 0.3 

sudo echo c > /proc/sysrq-trigger
