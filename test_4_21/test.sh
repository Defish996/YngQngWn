#!/bin/bash

# 设置要监控的进程名称列表
processes=("test" "process")

while true; do
    for process_name in "${processes[@]}"; do
        # 使用pgrep命令获取指定进程的PID
        pids=$(pgrep "$process_name")

        if [ -n "$pids" ]; then
            echo "Process $process_name is running:"
            # 遍历PID，使用ps命令获取进程信息
            for pid in $pids; do
                process_info=$(ps -p $pid -o comm=)
                echo "$process_info"
            done
        else
            echo "Process $process_name is not running."
        fi
    done

    # 可以调整监控的时间间隔，单位为秒
    echo "--------------------------------------"
    sleep 1
  done
