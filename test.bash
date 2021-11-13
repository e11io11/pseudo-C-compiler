echo \#syn-err:;
for file in test/syn-err/* ; do
echo $file
bin/tpcas < $file
echo $?
done
echo \#good:
for file in test/good/* ; do
echo $file
bin/tpcas < $file
echo $?
done