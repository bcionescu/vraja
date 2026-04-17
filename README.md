# Vraja (*vra-ya*)

A spellchecker written in C from scratch. To compile and run from Nvim, run this one-liner.

```nvim
:!make && ./build/vraja
```

# Current issue

After some investigation, it has become clear why loading the dictionary once is not working. It is because when iterating through `file`, we never reset. If the first word has 7 letters, once we find the match, it will continue from there for the second word, instead of starting from the start of the file once more.

# To Do
+ [ ] Finish implementing my own version of `strcpy()`
+ [ ] If a word is capitalized, convert it to lowercase first before processing.
+ [ ] Look into `mmap`, as that should make working with large dictionaries a lot easier.
+ [ ] When the algo improves, have a unit test where we remove the manual rules, and checks for them. The ones that the algo figures out we can remove. Or should we? They are faster to run. I’ll have to look into this.
+ [ ] Once we have our top 5, do a similarity check, out of those. Which one is the closest, and maybe give it some extra points. Maybe check the word against itself, getting the maximum possible number of points, and making that the baseline. Then, calculate the percentages of the other matches, based on their respective scores.
+ [ ] Add expressions such as "a lot" and "don't" in the dictionary. Alternatively, have them in their own dictionary, or hard code them into the .c file for now.
+ [ ] If we only have one letter, like x, or t, especially if it's ['q','w','d','x','z','`'] then it's probably just 'a'.
+ [ ] Maybe sometimes prioritise words of the same, or similar length, especially for very short words.
+ [ ] Pass a text via a file.
+ [ ] Check the text for words which do not appear in the dictionary.
+ [ ] Output the text to the console, writing the misspelled words in red text.
+ [ ] Next to each misspelled red word, add the potential matches in green, within parentheses. This will provide a compact way to showcase the potential matches.
