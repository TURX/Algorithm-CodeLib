operators = ['+', '-', '*', '/'];
expressions = dict();

def solve():
	global operators, expressions;
	for i in operators:
		for j in operators:
			for k in operators:
				toEval = "4" + i + "4" + j + "4" + k + "4";
				toEval = toEval.replace("4/4/4", "0");
				val = int(eval(toEval));
				if not val in expressions:
					expressions[val] = i + j + k;

if __name__ == "__main__":
	solve();
	# print(expressions);
	m = int(input());
	for i in range (0, m):
		n = int(input());
		if n in expressions:
			print("4 " + expressions[n][0] + " 4 " + expressions[n][1] + " 4 " + expressions[n][2] + " 4 = " + str(n));
		else:
			print("no solution");
