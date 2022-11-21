/*
 * @lc app=leetcode id=355 lang=typescript
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
  usersMap: Record<
    number,
    {
      followingMap: Record<number, true>;
      postsMap: Record<number, true>;
    }
  > = {};
  posts: { userId: number; tweetId: number }[] = [];
  constructor() {}

  _initUser(userId: number): void {
    if (!this.usersMap[userId]) {
      this.usersMap[userId] = {
        followingMap: {},
        postsMap: {},
      };
    }
  }
  _getUser(userId: number) {
    this._initUser(userId);
    return this.usersMap[userId];
  }

  postTweet(userId: number, tweetId: number): void {
    const user = this._getUser(userId);
    this.posts.push({ userId, tweetId });
    user.postsMap[tweetId] = true;
  }

  getNewsFeed(userId: number): number[] {
    const user = this._getUser(userId);
    let feed: number[] = [];
    for (let i = this.posts.length - 1; i >= 0; i--) {
      let post = this.posts[i];
      if (post.userId == userId || post.userId in user.followingMap) {
        feed.push(post.tweetId);
      }
      if (feed.length == 10) {
        break;
      }
    }
    return feed;
  }

  follow(followerId: number, followeeId: number): void {
    const user = this._getUser(followerId);
    user.followingMap[followeeId] = true;
  }

  unfollow(followerId: number, followeeId: number): void {
    const user = this._getUser(followerId);
    delete user.followingMap[followeeId];
  }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * var obj = new Twitter()
 * obj.postTweet(userId,tweetId)
 * var param_2 = obj.getNewsFeed(userId)
 * obj.follow(followerId,followeeId)
 * obj.unfollow(followerId,followeeId)
 */
// @lc code=end
