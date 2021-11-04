echo \#syn-err:;
for file in test/syn-err/* ; do
bin/tpcas < $file
done
echo \#good:
for file in test/good/* ; do
bin/tpcas < $file
done