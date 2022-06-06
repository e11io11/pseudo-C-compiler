res=0

echo \#good:
for file in test/good/* ; do
    echo $file
    bin/tpcc < $file
    current=$?
    echo $current
    if [[ $current -ne 0 ]]; then
        res=1
    fi
done
echo \#lex-err:
for file in test/lex-err/* ; do
    echo $file
    bin/tpcc < $file
    current=$?
    echo $current
    if [[ $current -ne 1 ]]; then
        res=1
    fi
done
echo \#sem-err:
for file in test/sem-err/* ; do
    echo $file
    bin/tpcc < $file
    current=$?
    echo $current
    if [[ $current -ne 1 ]]; then
        res=1
    fi
done
echo \#syn-err:
for file in test/syn-err/* ; do
    echo $file
    bin/tpcc < $file
    current=$?
    echo $current
    if [[ $current -ne 1 ]]; then
        res=1
    fi
done
echo \#all tests:
echo $res