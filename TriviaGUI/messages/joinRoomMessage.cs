using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace TriviaGUI
{
    public class joinRoomMessage
    {
        [DataMember(Order = 1)]
        public string roomId { get; set; }
    }
}
