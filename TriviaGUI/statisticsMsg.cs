﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI
{
    internal class statisticsMsg
    {
        [DataMember(Order = 1)]
        public int code { get; set; }
    }
}
