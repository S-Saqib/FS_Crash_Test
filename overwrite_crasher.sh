FILEPATH=""
if [ $# -eq 1 ]; then
    FILEPATH=$1
fi

./blk_writer $FILEPATH &

sleep 0.2 

sudo reboot
