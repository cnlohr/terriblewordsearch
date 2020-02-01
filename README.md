# terriblewordsearch
A C tool for making terrible word searches.

A long time ago I saw a "DOG" word search, in which there were a bunch of letters and only one "DOG" so I was curious how hard it would be to write a program to make terrible word searches. The answer was, very easy.

I wrote a program that creates them in C. It took about 30 minutes. It simply produces letters from a list of letters I provide it, and checks to make sure that the word in the search does not show up. If that word does show up, it starts rewriting some letters. Eventually, it creates a wordsearch without the word that you're searching for.

You then have to add the word in the search yourself.

Usage: ./wordsearch [x] [y] [word] [letter dictionary]

For example:

```
./wordsearch 10 10 the the
HITS: 59
h h t h h t t h t t 
h h e e t t e e e h 
h h e t t t e t h h 
h h t t t e e h e e 
e t e h h e e t e e 
h h t h t h t t t e 
e t e h e e t t e e 
h t t e t h h h t t 
e t e e t h h h h h 
t t t h h e h h t h 
```

Notice how the word "the" does not appear in the word search at all. You simply have to change the letters to add that word and you're set! You have made a terrible word search.

Here are some examples:

!(https://raw.githubusercontent.com/cnlohr/terriblewordsearch/master/kayak.png)
!(https://raw.githubusercontent.com/cnlohr/terriblewordsearch/master/bonobo.png)
!(https://raw.githubusercontent.com/cnlohr/terriblewordsearch/master/mississippi.png)
!(https://raw.githubusercontent.com/cnlohr/terriblewordsearch/master/the2.png)
