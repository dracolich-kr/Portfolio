using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace DataBaseParser
{
    public static class ExFunc
    {
        public static String toString(this InoutType inout_type)
        {
            switch(inout_type)
            {
                case InoutType.Input:
                    return "SQL_PARAM_INPUT";
                case InoutType.OutPut:
                    return "SQL_PARAM_OUTPUT";
                case InoutType.InoutPut:
                    return "SQL_PARAM_INOUTPUT";
            }

            return "None";
        }

        public static String toSqlTypeString(this ValueType value_type)
        {
            switch(value_type)
            {
                case ValueType.Bit:
                    return "Bool";
                case ValueType.TinyInt:
                    return "SqlInt8";
                case ValueType.SmallInt:
                    return "SqlInt16";
                case ValueType.Int:
                    return "SqlInt32";
                case ValueType.Bigint:
                    return "SqlInt64";
                case ValueType.NVarChar:
                    return "SqlWString";
                case ValueType.Float:
                    return "SqlFloat";
                case ValueType.Double:
                    return "SqlDouble";
                case ValueType.DateTime:
                    return "SqlDateTime";
            }

            return "None";
        }

        public static String toTypeString(this ValueType value_type)
        {
            switch (value_type)
            {
                case ValueType.Bit:
                    return "Bool";
                case ValueType.TinyInt:
                    return "Int8";
                case ValueType.SmallInt:
                    return "Int16";
                case ValueType.Int:
                    return "Int32";
                case ValueType.Bigint:
                    return "Int64";
                case ValueType.NVarChar:
                    return "DefWString";
                case ValueType.Float:
                    return "Float";
                case ValueType.Double:
                    return "Double";
                case ValueType.DateTime:
                    return "DateTime";
            }

            return "None";
        }
    }
}