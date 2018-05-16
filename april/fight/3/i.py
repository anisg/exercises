
# Write your code here
T = int(raw_input())
for t in range(0, T):
    words = raw_input().split()
    n = len(words)
    res = [words[i] for i in range(0, n)]
    for i in range(0, n/2):
        res[i] = words[n-1-i]
        res[n-1-i] = words[i]
    s = ""
    for i in range(0, n):
        s += res[i] + " "
    print(s.strip())
