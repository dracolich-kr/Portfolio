using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace DataBaseParser
{
    public enum ValueType
    {
        None = 0
        , Bit = 1
        , TinyInt = 2
        , SmallInt = 3
        , Int = 4
        , Bigint = 5
        , Float = 6
        , Double = 7
        , NVarChar = 8
        , DateTime = 9
    }

    public class SqlValue
    {
        public ValueType Type { get; set; } = ValueType.None;
        public String Name { get; set; } = String.Empty;
        public Int32 Length { get; set; } = 0;
    }
}