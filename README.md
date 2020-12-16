# Working Shift Scheduling

The government executes the new policy of One Mandatory Day Off One Flexible Rest Day(一例一休), resulting in the difficulties of scheduling by manual work. In view of this, I develop a program to schedule working shift arrangement for the Building Management Department of Windsor Hotel,  Taichung(台中裕元花園酒店).The **operating research algorithm** is employed to develop this project.

## Spec

**Z** : day-off
**A** : 8:00 ~ 16:30(8.5 H)
**B** : 15:30 ~ 24:00(8.5H)
**C** : 24:00 ~ 8:00(8H)
**D** : 8:00 ~ 17:00(9H)

1. Workers cannot work for more than 8 hours a day.
2. Workers cannot work for more than 6 days a week.
3. Each group had better work with two or more workers in a day.
4. At least one person in each group works in a day.
5. Workers want to rest on weekends.
6. Workers have choice to select which day they want to rest.
7. Workers have the right to choose which day for a day-off.


## Input

1. Schedule of last month
2. Calendar of current month
3. Calendar of next month
4. Scheduling Rule

## Output

Schedule of current month and the first 7 days of next month.

## Result

```
GroupA
Date  25  26  27  28  29  30  31  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  1   2   3   4   5   6   7
Day   Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat
吳榮鈞  D   D   Z   D   Z   Z   D   Z   D   D   Z   D   D   D   D   Z   D   Z   D   Z   D   D   D   D   Z   D   D   Z   D   D   Z   D   D   D   D   Z   D   D   Z   D   Z   D   Z   D
李世鴻  B   Z   B   B   B   B   Z   A   A   Z   Z   A   Z   A   A   A   A   A   Z   A   Z   A   A   Z   A   A   Z   A   Z   A   A   A   A   A   Z   A   A   C   Z   C   Z   C   C   C
羅國祐  C   C   Z   C   C   C   C   A   Z   A   A   A   Z   A   Z   A   Z   A   A   A   A   A   Z   A   Z   Z   A   A   A   Z   A   Z   A   A   A   A   A   Z   B   B   B   Z   B   B

GroupB
Date  25  26  27  28  29  30  31  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  1   2   3   4   5   6   7
Day   Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat
劉昌仁  A   A   A   Z   A   A   A   B   Z   B   B   B   Z   B   B   Z   B   B   B   Z   Z   B   Z   B   B   B   B   B   Z   B   B   B   Z   B   B   Z   B   Z   Z   C   C   Z   C   C
陳修緯  C   C   C   Z   Z   C   C   B   B   Z   B   B   B   Z   B   B   B   Z   B   B   Z   B   B   Z   Z   B   Z   B   B   B   Z   B   B   B   Z   B   B   C   Z   C   C   C   C   Z
黃裕淵  C   C   Z   C   C   C   Z   B   B   Z   B   Z   Z   B   B   B   B   B   Z   B   B   Z   B   B   B   B   B   Z   B   B   B   Z   B   Z   B   B   Z   Z   A   Z   A   A   A   A

GroupC
Date  25  26  27  28  29  30  31  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  1   2   3   4   5   6   7
Day   Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat Sun Mon Tue Wed Thu Fri Sat
林建弘  B   B   B   B   Z   B   B   C   C   Z   C   C   C   Z   C   C   Z   Z   C   C   C   Z   C   Z   C   C   C   Z   C   C   C   Z   Z   C   C   C   C   B   Z   B   Z   B   Z   B
洪博章  B   B   B   B   B   Z   B   C   Z   C   C   C   Z   Z   Z   C   C   C   C   C   Z   C   C   C   C   Z   C   C   C   Z   C   C   C   C   C   Z   Z   A   Z   A   Z   A   A   A
陳榮洲  Z   Z   Z   A   A   A   A   Z   C   C   C   C   C   Z   C   C   Z   C   Z   C   C   C   C   C   Z   C   C   C   Z   C   Z   Z   C   C   Z   C   C   B   Z   B   B   B   B   Z

Quality ============
劉昌仁 18000
吳榮鈞 20000
李世鴻 20000
林建弘 20000
洪博章 20000
羅國祐 14000
陳修緯 18000
陳榮洲 16000
黃文松 172000
黃裕淵 18000
qAmin = 50000
qBmin = 58000
qCmin = 60000
```

## Build

### Step 1 build libary dependency
```shell=
$ cd lib
$ make all
```

### Step 2 make
```shell=
$ cd objects
$ make main
```

### Step 3 Execute
```shell=
$ ./main
```

## Todo

- [ ] Genetic operation : mutation, crossover.
- [ ] Enable define scheduling range.
- [ ] Enable load history shift.
- [ ] Python GUI development.
- [ ] Simulation and optimization.
