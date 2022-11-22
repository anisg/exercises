/*
 * @lc app=leetcode id=1396 lang=typescript
 *
 * [1396] Design Underground System
 */

// @lc code=start
/** follow the form `${station1}->${station2}` */
type Station1ToStation2Str = string;
class UndergroundSystem {
  travelAverageTimesMap: Record<
    Station1ToStation2Str,
    {
      total: number;
      count: number;
    }
  > = {};
  pendingCheckInUsersMap: Record<number, { stationName: string; t: number }> =
    {};
  constructor() {}

  checkIn(id: number, stationName: string, t: number): void {
    this.pendingCheckInUsersMap[id] = { stationName, t };
  }

  checkOut(id: number, stationName: string, t: number): void {
    const startStation = this.pendingCheckInUsersMap[id].stationName;
    const time = t - this.pendingCheckInUsersMap[id].t;
    this.travelAverageTimesMap[`${startStation}->${stationName}`] = this
      .travelAverageTimesMap[`${startStation}->${stationName}`] || {
      total: 0,
      count: 0,
    };
    this.travelAverageTimesMap[`${startStation}->${stationName}`].total += time;
    this.travelAverageTimesMap[`${startStation}->${stationName}`].count++;
  }

  getAverageTime(startStation: string, endStation: string): number {
    const { total, count } =
      this.travelAverageTimesMap[`${startStation}->${endStation}`];
    return total / count;
  }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * var obj = new UndergroundSystem()
 * obj.checkIn(id,stationName,t)
 * obj.checkOut(id,stationName,t)
 * var param_3 = obj.getAverageTime(startStation,endStation)
 */
// @lc code=end
