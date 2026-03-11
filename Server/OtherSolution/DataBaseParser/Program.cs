using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBaseParser
{
    internal class Program
    {
        static void Main(string[] args)
        {
            String target_sql_path = args[0];
            String output_path = args[1];

            ParsorEngine engine = new ParsorEngine();
            engine.Work(target_sql_path, output_path);
        }
    }
}
