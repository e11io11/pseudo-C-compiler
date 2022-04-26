res=0

echo \#good:
for file in test/good/* ; do
    echo $file
    bin/tpcas < $file
    current=$?
    echo $current
    if [[ $current -ne 0 ]]; then
        res=1
    fi
done
echo \#all tests:
echo $res