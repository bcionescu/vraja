# Vraja (*vra-ya*)

A spellchecker written in C from scratch. To compile and run from Nvim, run this one-liner. This project is still a work in progress. For your convenience, I made a [YouTube video](https://www.youtube.com/watch?v=j-5sgued3RM), going through the code and explaining how this program works.

## Motivation

When solving real-world problems, solutions are often not publicly available. If I had to make the first spell checker, how would I do it? How would I personally approach an initial solution to the problem?

## Quick Start

Navigate to the project directory, and create a binary file.

```bash
make ./build/vraja
```

## Usage

```bash
./build/vraja "the quik brown foox jumps ovr the lazy dogg"
```

The current version of the program only accepts lower-case words, with no punctuation. The example above will produce the following output.

```bash
quik -> quirk [24] quick [24] [0.093ms] -> 150 entries
foox -> fox [32] [0.579ms] -> 1374 entries
ovr -> over [28] [0.184ms] -> 338 entries
dogg -> dog [24] dogleg [23] [0.457ms] -> 1543 entries
```

## Advanced Usage

At the top of the `spell_check` function in `spell_check.c` you will find a number of macros.

Currently, the algorithm only displays a maximum of three results, in the top 95% of scores. In other words, if, for example, the 2nd highest rated match is not within 95% of the 1st score, it will not be displayed. By adjusting these two numbers, you can make the output more or less strict.

`MAX_ENTRIES` allows you to configure the maximum number of entries. Even if you increase it, you may notice that the program might still display only one or two. This is because of the next macro called `SCORE_LIMITER`.

By default, the score limiter is set to 0.95, meaning that once the first match is obtained, if the score of the following matches do not fall within 95% of the first, they will not be displayed. Thus, if you wish to see more matches, you need to both increase `MAX_ENTRIES` and decrease `SCORE_LIMITER`.

The other macros also allow you to control the output. So, if you do not wish to see the score of each match, the time it took to generate them, or the number of entries that the program searched through for that particular word, you can set them to `0`.

## To Do
+ [ ] Look into `mmap`, as that should make working with large dictionaries a lot easier.
+ [ ] Finish implementing my own version of `strcpy()`
+ [ ] When the algo improves, have a unit test where we remove the manual rules, and checks for them. The ones that the algo figures out we can remove. Or should we? They are faster to run. I’ll have to look into this.
+ [ ] Add expressions such as "a lot" and "don't" in the dictionary.
+ [ ] If we only have one letter, like x, or t, especially if it's ['q','w','d','x','z','`'] then it's probably just 'a'.

## Contributing

For the time being, I am not accepting contributions. This is because I’d like to learn as much as possible. Eventually, you will be able to help make this project better.
