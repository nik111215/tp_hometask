#!/bin/bash
dir=$1
ext=$2
name=$3
arxiv=$4

pdir=$(find $dir -name "*.$ext")

number=1
mkdir $name
for i in $pdir
do
cp $i "$name/$number"_"$(basename $i)"
let "number+=1"
done

tar -czf $arxiv $name

echo "done"

