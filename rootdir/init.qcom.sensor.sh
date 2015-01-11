start_sensors()
{
    if [ -c /dev/msm_dsps -o -c /dev/sensors ]; then
        mkdir -p /data/system/sensors
        touch /data/system/sensors/settings
        chmod 775 /data/system/sensors
        chmod 664 /data/system/sensors/settings
        chown system /data/system/sensors/settings

        mkdir -p /data/misc/sensors
        chmod 775 /data/misc/sensors

        if [ ! -s /data/system/sensors/settings ]; then
            # If the settings file is empty, enable sensors HAL
            # Otherwise leave the file with it's current contents
            echo 1 > /data/system/sensors/settings
        fi
        start sensors
    fi
}

start_sensors
