#!/bin/sh

# binary to decimal
BinToDec(){
    # binNum="101100100011001000000000"
    binNum="$1"
    pow=0;
    len=$((${#binNum}-1))
    for i in $(seq 0 $len); do
        value=$((value+$(($((2**$i))*${binNum:$(($len-$i)):1}))))
        # echo "i:$i bit:${binNum:$i:1} pow:$((2**$i)) value:$value"
    done
    echo $value
}

# decimal to binary
DecToBin()
{
   val=$1
   base=2
   reveal=$2
   result=""
   while [ $val -ne 0 ] ; do
        result=$(( $val % $base ))$result #residual is next digit
        val=$(( $val / $base ))
   done
   printf "%0${reveal}d" "$result" 2> /dev/null
}

# printf "%x" "$value"
