using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI
{
    public class updateMessage
    {
        [DataMember(Order = 1)]
        public string username { get; set; }

        [DataMember(Order = 2)]
        public string password { get; set; }
    }
}
