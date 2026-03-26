# Vraja (vrah-jah)

A spellchecker written in C from scratch.

# To Do

+ [x] Assemble a dictionary.
+ [x] Pass misspelled words through an array.
+ [x] Start off by passing a word at a time.
+ [x] Tokenize each incorrect word in the string, and in the dictionary, into groups of three of less.
+ [x] Compare the first token in the misspelled word with the first token of every word in the dictionary which is +/-2 of the total length of the misspelled word. Do so by checking if each letter of the token appears in the dictionary word token, in any order. With each loose match, increment the score of the word by one. If we have a partial match, such as two letters in a row, increment it by two points, and if we have an exact match, increment it by three.
+ [x] Repeat this process with every matching length word in the dictionary, until we run out.
+ [x] Order the suggestions from highest to lowest. This way, the highest matching word will come up first.
+ [x] If we have multiple words with the same score, prioritise results of the exact same length as the misspelling. If we still have a tie, prioritise the word that starts with the same letter as the misspelled word, as I suspect errors are more likely to occur later in the word, as opposed to the start.
+ [x] The if statements in the manual rules function are very inefficient. Not only do we check every single one, but we also check them all for each potential match. All we need to do is check whether the misspelling is in that list. If so, return the correct spelling. Maybe use a struct.
+ [ ] Once we have our top 5, do a similarity check, out of those. Which one is the closest, and maybe give it some extra points. Maybe check the word against itself, getting the maximum possible number of points, and making that the baseline. Then, calculate the percentages of the other matches, based on their respective scores.
+ [ ] The current version of the algo gives higher scores to longer words. This is a problem, so the scores need to be adjusted based on the length. Maybe even something like dividing the score by the length of the word.
+ [ ] Add expressions such as "a lot" and "don't" in the dictionary. Alternatively, have them in their own dictionary, or hard code them into the .c file for now.
+ [ ] If we only have one letter, like x, or t, especially if it's ['q','w','d','x','z','`'] then it's probably just 'a'.
+ [ ] Maybe sometimes prioritise words of the same, or similar length, especially for very short words.
+ [ ] Short words are more likely to not have the last group calculated. We still need to take that into account, and award some points for it.
+ [ ] Pass a text via a file.
+ [ ] Check the text for words which do not appear in the dictionary.
+ [ ] Output the text to the console, writing the misspelled words in red text.

Words that still need manual rules:

alot -> a lot || allot
alright -> all right
abouta->about a
aboutit->about it
aboutthe->about the
admendment->amendment
admissability->admissibility
adquire->acquire
adquired->acquired
adquires->acquires
adquiring->acquiring
adres->address
adresable->addressable
adresing->addressing
adviced->advised
aeriels->aerials
affort->afford, effort
agains->against
aggreement->agreement
aggregious->egregious
aggregrator->aggregator
agian->again
agin->again
agina->again, angina
aginst->against
ahev->have
ahppen->happen
ahve->have
aircrafts->aircraft
alcohal->alcohol
alcoholical->alcoholic
aledges->alleges
algebraical->algebraic
algoritm->algorithm
allegedely->allegedly
allegedy->allegedly


 {"countrie's", "countries, countries', country's", "didnt", "didn't", "doesnt", "doesn't", "dosen't", "doesn't", "hasnt", "hasn't", "isnt", "isn't", "shoudln", "should, shouldn't", "thast", "that, that's", "theyre", "they're", "todays", "today's", "wasnt", "wasn't", "alltime", "all-time", "antiapartheid", "anti-apartheid", "Coca Cola", "Coca-Cola", "co", "ncided->coincided", "aircrafts'", "aircraft's"};

 Gemini said

Aren't
Can't
Couldn't
Daren't
Didn't
Doesn't
Don't
Hadn't
Hasn't
Haven't
He'd
He'll
He's
How'd
How'll
How's
I'd
I'll
I'm
I've
Isn't
It'd
It'll
It's
Let's
Ma'am
Mayn't
Mightn't
Mustn't
Needn't
O'clock
Oughtn't
Shan't
She'd
She'll
She's
Shouldn't
Should've
That'd
That'll
That's
There'd
There'll
There's
They'd
They'll
They're
They've
Wasn't
We'd
We'll
We're
We've
Weren't
What'd
What'll
What're
What's
What've
When's
Where'd
Where's
Where've
Who'd
Who'll
Who're
Who's
Who've
Why'd
Why'll
Why's
Won't
Wouldn't
Would've
You'd
You'll
You're
You've

Gonna (Going to)
Wanna (Want to)
Gotta (Got to / Have to)
Dunno (Don't know)
Kinda (Kind of)
Sorta (Sort of)
Outta (Out of)
Gimme (Give me)
Lemme (Let me)
Tell'em Tellem (Tell them)
Cos (Because)
Shoulda (Should have)
Coulda (Could have)
Woulda (Would have)
Musta (Must have)
Mighta (Might have)
Lotsa (Lots of)
Whatcha (What are you)
Gotcha (Got you)
Betcha (Bet you)
