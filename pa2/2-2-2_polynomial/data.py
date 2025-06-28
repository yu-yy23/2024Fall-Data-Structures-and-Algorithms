import sympy as sp
import random

def generate_complex_polynomial(depth=100, max_terms=5):
    x = sp.symbols('x')
    
    def generate_term():
        # 随机生成系数和指数
        coefficient = random.randint(1, 5) * random.choice([-1, 1])
        degree = random.randint(1, 3)
        return coefficient * x**degree

    def generate_expression(current_depth):
        if current_depth >= depth or random.random() > 0.5:
            return generate_term()
        
        # 随机选择操作符
        operation = random.choice(['+', '-', '*', '**'])
        
        if operation in ['+', '-']:
            return generate_expression(current_depth + 1) + generate_expression(current_depth + 1) if operation == '+' else generate_expression(current_depth + 1) - generate_expression(current_depth + 1)
        elif operation == '*':
            return generate_expression(current_depth + 1) * generate_expression(current_depth + 1)
        elif operation == '**':
            return generate_expression(current_depth + 1) ** random.randint(1, 3)

    # 生成多项式表达式
    expression = generate_expression(0)
    
    # 简化表达式
    simplified_expression = sp.simplify(expression)
    
    return simplified_expression

# 示例使用
if __name__ == "__main__":
    #random.seed(42)  # 设置随机种子以便于调试
    polynomial = generate_complex_polynomial()
    print(polynomial)