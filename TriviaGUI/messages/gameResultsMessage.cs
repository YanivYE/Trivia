﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI.messages
{
    internal class gameResultsMessage
    {
        [DataMember(Order = 1)]
        public string score { get; set; }
    }
}
