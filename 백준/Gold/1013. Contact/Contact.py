import re
print(*[["YES","NO"][re.fullmatch("(100+1+|01)+", input()) is None]for _ in range(int(input()))],sep='\n')