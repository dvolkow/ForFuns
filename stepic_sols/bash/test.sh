#! /bin/bash

ifl=1
res=0
op=0

function calc()
{
    op=$2;
    local fisrt=$1
    local second=$3
    case "$op" in 
        '+') let "res = second + fisrt" 
            ;;
        '-') let "res = fisrt - second " 
            ;;
        '*') let "res = fisrt * second " 
            ;;
        '**') res=`echo "$(( $fisrt ** $second ))"` 
            ;;
        '/') let "res = fisrt / second " 
            ;;
        '%') let "res = fisrt % second " 
            ;;
        *)  ifl=0
            ;;
    esac
}

while [[ true ]] ; do

    read a b c
    if [[ $a == "exit" ]] ; then 
        echo "bye"
        exit 0
    else 
        calc $a "$b" $c
        if [[ $ifl -eq 0 ]] ; then
            echo "error"
            exit 0
        else 
            echo $res
        fi
    fi
done
