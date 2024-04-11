using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI.messages
{
    public class createRoomMessage
    {
        [DataMember(Order = 1)]
        public string roomName { get; set; }

        [DataMember(Order = 2)]
        public string maxUsers { get; set; }
        [DataMember(Order = 3)]
        public string questionCount { get; set; }
        [DataMember(Order = 4)]
        public string answerTimeout { get; set; }
    }
}
