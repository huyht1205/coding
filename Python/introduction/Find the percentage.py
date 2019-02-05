# Enter your code here. Read input from STDIN. Print output to STDOUT

N = int(raw_input())

new_dict = dict()

for i in range(0, N) :
        name, grade1, grade2, grade3 = raw_input().split(' ')
        name = str(name)
        grade1 = float(grade1)
        grade2 = float(grade2)
        grade3 = float(grade3)
        grade = float((grade1 + grade2 + grade3) / 3.00)
        new_dict[name] = grade

query = raw_input()
print "%.2f" % (new_dict.get(query))
        