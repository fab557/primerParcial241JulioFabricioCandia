using System;
using System.Collections.Generic;

class Calculator
{
    // Método para evaluar la expresión en notación postfija (RPN)
    public static double EvaluateRPN(string[] tokens)
    {
        Stack<double> stack = new Stack<double>();

        foreach (var token in tokens)
        {
            if (double.TryParse(token, out double number))
            {
                stack.Push(number);
            }
            else if (stack.Count >= 2) // Asegúrate de que haya al menos dos elementos
            {
                double b = stack.Pop();
                double a = stack.Pop();
                switch (token)
                {
                    case "+":
                        stack.Push(a + b);
                        break;
                    case "-":
                        stack.Push(a - b);
                        break;
                    case "*":
                        stack.Push(a * b);
                        break;
                    case "/":
                        stack.Push(a / b);
                        break;
                }
            }
        }

        // Asegúrate de que la pila tenga un solo resultado
        if (stack.Count != 1)
        {
            throw new InvalidOperationException("Error en la evaluación de la expresión.");
        }

        return stack.Pop();
    }

    // Método para convertir la expresión infija a notación postfija (RPN)
    public static string[] InfixToPostfix(string expression)
    {
        List<string> output = new List<string>();
        Stack<char> operators = new Stack<char>();
        string[] tokens = expression.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

        foreach (var token in tokens)
        {
            if (double.TryParse(token, out _))
            {
                output.Add(token);
            }
            else if (token == "(")
            {
                operators.Push('(');
            }
            else if (token == ")")
            {
                while (operators.Count > 0 && operators.Peek() != '(')
                {
                    output.Add(operators.Pop().ToString());
                }
                if (operators.Count > 0)
                {
                    operators.Pop(); // Eliminar '('
                }
            }
            else // Operadores
            {
                while (operators.Count > 0 && Precedence(token[0]) <= Precedence(operators.Peek()))
                {
                    output.Add(operators.Pop().ToString());
                }
                operators.Push(token[0]);
            }
        }

        while (operators.Count > 0)
        {
            output.Add(operators.Pop().ToString());
        }

        return output.ToArray();
    }

    // Método para obtener la precedencia de los operadores
    private static int Precedence(char op)
    {
        switch (op)
        {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3; // Potenciación
            default:
                return 0;
        }
    }

    public static void Main(string[] args)
    {
        Console.WriteLine("Ingrese una expresión matemática (por ejemplo: 3 + 4 * 2 / ( 1 - 5 ) ^ 2):");
        string expression = Console.ReadLine();

        // Asegúrate de que no haya espacios extraños
        expression = expression.Trim();

        var postfix = InfixToPostfix(expression);

        // Verifica si la conversión a RPN fue exitosa
        if (postfix.Length == 0)
        {
            Console.WriteLine("Error en la conversión a postfijo.");
            return;
        }

        double result = EvaluateRPN(postfix);
        Console.WriteLine($"Resultado: {result}");
    }
}
