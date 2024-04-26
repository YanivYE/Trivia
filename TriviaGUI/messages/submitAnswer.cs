using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI.messages
{
    internal class submitAnswer
    {
        [DataMember(Order = 1)]
        public string ID { get; set; }

        [DataMember(Order = 2)]
        public string time { get; set; }
    }
}
