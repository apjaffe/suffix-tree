ByteSubstringsChallenge.js submission

(Contact me via GitHub in case of any questions)

All rights reserved, including copyright. (Note that this project was forked from the suffix-tree library. More information about that project is in the other README file.)

Usage:

First, put the input in input.txt. Then:

```
make challenge
./challenge > output.json
```

Caveats:

Runtime is O(n) + O(output size) through use of suffix trees. Unfortunately, the output for big.txt is extremely large, so there's not much I can do about that.

There will be strange behavior if your input includes a dollar sign or a quotation mark. I recommend just removing these for now, and if you like the solution you can find hacks to work around this issue later.

