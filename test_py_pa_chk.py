import os
for i in range(1, 11):
    os.system(f"copy aplusb{i}.in aplus.in")
    os.system("aplusb.exe")
    os.system(f"fc aplusb.out aplus{i}.ans")
    os.system("")