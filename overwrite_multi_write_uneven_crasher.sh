FILEPATH=""
BLOCKCOUNT=""

if [ $# -ge 1 ]; then
    FILEPATH=$1
fi

if [ $# -ge 2 ]; then
    BLOCKCOUNT=$2
fi

./blk_writer_multi_write_uneven $FILEPATH $BLOCKCOUNT &

sleep 0.3

sudo echo c > /proc/sysrq-trigger
