TEST_BIN=$1

while IFS= read -r line
do
	./"$TEST_BIN" "$line"
done < "$TEST_BIN"_inputs
