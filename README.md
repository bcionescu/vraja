# Vraja (*vra-ya*)

A spellchecker written in C from scratch. To compile and run from Nvim, run this one-liner. This project is still a work in progress. For your convenience, I made a [YouTube video](https://www.youtube.com/watch?v=j-5sgued3RM), going through the code and explaining how this program works.

## Quick Start

First, navigate to the project directory, and create a binary file.

```bash
make ./build/vraja
```

Then, run it.

```bash
./build/vraja
```

Alternatively, you can build and run the program straight from Neovim.

```nvim
:!make && ./build/vraja
```

## How Do You Use It?

At the top of the `main` function in `vraja.c` you will find an array called `misspelled`. Fill it with words that you want to test. At the top of the `vraja.c` file itself, you will find `#define INCLUDE_MANUAL 0`. If you want to purely use the algorithm, leave it as it is. If, however, you wish to use a manual list of rules, set it to `1`.

This will match misspellings to a preset list of correct spellings. It’s faster, and makes the program more accurate, but right now I’m still improving the algorithm itself.

Currently, the algorithm only displays a maximum of three results, in the top 95% of scores. In other words, if, for example, the 2nd highest rated match is not within 95% of the 1st score, it will not be displayed. By adjusting these two numbers, you can make the output more or less strict.

If you wish to play with these parameters, you can find their corresponding macros at the top of the `vraja.c` file.

`MAX_ENTRIES` allows you to configure the maximum number of entries. Even if you increase it, you may notice that the program might still display only one or two. This is because of the next macro called `SCORE_LIMITER`.

By default, the score limiter is set to 0.95, meaning that once the first match is obtained, if the score of the following matches do not fall within 95% of the first, they will not be displayed. Thus, if you wish to see more matches, you need to both increase `MAX_ENTRIES` and decrease `SCORE_LIMITER`.

The other macros also allow you to control the output. So, if you do not wish to see the score of each match, the time it took to generate them, or the number of entries that the program searched through for that particular word, you can set them to `0`.

## To Do
+ [ ] Implement the ability to provide words via args. If present, ignore the array, and use the arguments instead.
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


