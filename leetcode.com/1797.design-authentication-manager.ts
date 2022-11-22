/*
 * @lc app=leetcode id=1797 lang=typescript
 *
 * [1797] Design Authentication Manager
 */

// @lc code=start
class AuthenticationManager {
  tokens: { tokenId: string; expiresAt: number }[] = [];
  timesToLive: number;
  constructor(timeToLive: number) {
    this.timesToLive = timeToLive;
  }

  generate(tokenId: string, currentTime: number): void {
    this.tokens.push({
      tokenId,
      expiresAt: currentTime + this.timesToLive,
    });
  }

  _isUnexpired(
    token: { tokenId: string; expiresAt: number },
    currentTime: number
  ): boolean {
    return token.expiresAt >= currentTime;
  }

  renew(tokenId: string, currentTime: number): void {
    const token = this.tokens.find((token) => token.tokenId === tokenId);
    if (!token) return;
    this.tokens = this.tokens.filter((token) => token.tokenId !== tokenId);
    if (this._isUnexpired(token, currentTime)) {
      this.generate(tokenId, currentTime);
    }
  }

  countUnexpiredTokens(currentTime: number): number {
    return this.tokens.filter((token) => this._isUnexpired(token, currentTime))
      .length;
  }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * var obj = new AuthenticationManager(timeToLive)
 * obj.generate(tokenId,currentTime)
 * obj.renew(tokenId,currentTime)
 * var param_3 = obj.countUnexpiredTokens(currentTime)
 */
// @lc code=end
