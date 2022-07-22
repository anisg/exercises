/*
 * @lc app=leetcode id=500 lang=typescript
 *
 * [500] Keyboard Row
 */

// @lc code=start
function findWords(words: string[]): string[] {
  return words.filter((word) => isInOneOfKeyboardRows(word));

  function isInOneOfKeyboardRows(word: string) {
    const keyrows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"].map((listchars) =>
      listchars.split("")
    );

    return keyrows.some((keyrow) => {
      return word
        .toLowerCase()
        .split("")
        .every((character) => keyrow.includes(character));
    });
  }
}
// @lc code=end
