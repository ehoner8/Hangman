./hangman "don't go in empty-handed" < tester.txt > resiflose.txt
diff resiflose.txt lose.txt
if [ $? -ne 0 ]; then
	echo "standard out doesn't match!"
	exit 1
fi

echo "Working Correctly for lose.txt"

./hangman zyxwvutsrqponmlkjihgfedcba < tester.txt > resifwin.txt
diff resifwin.txt win.txt
if [ $? -ne 0 ]; then
	echo "standard out doesn't match!"
	exit 1
fi

echo "Working Correctly for win.txt"
exit 0

