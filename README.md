# Vraja (*vra-ya*)

A spellchecker written in C from scratch. To compile and run from Nvim, run this one-liner. This project is still a work in progress. There’s so much that I want to add and improve, but I wanted to release the code in this early state.

```nvim
:!make && ./build/vraja
```

## To Do
+ [ ] Look into `mmap`, as that should make working with large dictionaries a lot easier.
+ [ ] Finish implementing my own version of `strcpy()`
+ [ ] When the algo improves, have a unit test where we remove the manual rules, and checks for them. The ones that the algo figures out we can remove. Or should we? They are faster to run. I’ll have to look into this.
+ [ ] Add expressions such as "a lot" and "don't" in the dictionary.
+ [ ] If we only have one letter, like x, or t, especially if it's ['q','w','d','x','z','`'] then it's probably just 'a'.

## Documentation

`The README is a work in progress, and it will be completed soon.`

Why build a spellchecker, when this problem has been solved, and why do it in C? Why did I not look up how to do a spellchecker, instead opting to figure it out by myself?

When solving a real problem, you will encounter problems which not many people have dealt with. This means that you will be unable to look up the solution. Google will not have it, and neither will your favourite LLM. In such a scenario, you become a pioneer. You will have to solve the problem, and push technology further.

Looking up solutions does not foster such a mentality. This is why I chose to write my own spellchecker, without looking up existing algorithms or methods. Because I want to work on projects that matter; programs that move the needle, and in order to do this, I must be able to solve problems.

### How does this work?


