import collections
class Solution(object):
    '''
    思路：
        1、遍历找到第level层的好友
        2、找出好友对应ID的watchVideos
        3、排序watchVideos
    '''
    def watchedVideosByFriends(self, watchedVideos, friends, id, level):
        now = 0
        flag = set()
        fre = set([id])
        videos = []

        while now < level:
            tmp = set()
            for i in fre:
                if i in flag:  # 已经访问过的好友不算
                    continue
                flag.add(i)
                tmp.update(friends[i])
            fre = tmp
            now += 1
        fre = [x for x in fre if x not in flag]  # 去除已经访问过的

        for f in fre:
            for v in watchedVideos[f]:
                videos.append(v)
        result = collections.defaultdict(int)
        for v in videos:
            result[v] += 1

        c = sorted(result.items(), key=lambda x: (x[1], x[0]))
        res = []
        for k, v in c:
            res.append(k)
        return res

if __name__ == '__main__':
    watchedVideos = [["A", "B"], ["C"], ["B", "C"], ["D"]]
    friends = [[1, 2], [0, 3], [0, 3]]
    id =0
    level =2
    print(Solution().watchedVideosByFriends(watchedVideos,friends, id, level))



