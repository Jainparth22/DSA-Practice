# LC#150 — Evaluate Reverse Polish Notation
# Difficulty: Medium | Pattern: Stack | Time: O(n) | Space: O(n)
def eval_rpn(tokens):
    st = []
    for t in tokens:
        if t in "+-*/" and len(t) == 1:
            b, a = st.pop(), st.pop()
            st.append(a + b if t == "+" else a - b if t == "-" else a * b if t == "*" else int(a / b))
        else:
            st.append(int(t))
    return st[0]

assert eval_rpn(["2","1","+","3","*"]) == 9 and eval_rpn(["4","13","5","/","+"]) == 6
