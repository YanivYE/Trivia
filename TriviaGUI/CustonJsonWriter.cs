using System;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace TriviaGUI
{
    public class CustomJsonWriter : Utf8JsonWriter
    {
        private int indentLevel = 0;

        public CustomJsonWriter(System.IO.Stream stream, JsonSerializerOptions options)
            : base(stream, options)
        {
        }

        protected override void WriteIndentation()
        {
            if (Options.WriteIndented)
            {
                WriteWhitespace(Environment.NewLine);
                WriteWhitespace(new string(' ', indentLevel * 4));
            }
        }

        public override void WriteStartObject()
        {
            base.WriteStartObject();
            indentLevel++;
        }

        public override void WriteEndObject()
        {
            base.WriteEndObject();
            indentLevel--;
        }
    }

    public class Data
    {
        public string Username { get; set; }
        public string Password { get; set; }
    }

    public static void Main()
    {
        // Create an instance of the Data class with the strings
        Data data = new Data
        {
            Username = "yaniv",
            Password = "mom"
        };

        // Configure JSON serializer options
        var options = new JsonSerializerOptions
        {
            PropertyNamingPolicy = JsonNamingPolicy.CamelCase,
            WriteIndented = true
        };

        // Serialize the object to JSON with custom formatter
        string jsonString;
        using (var stream = new System.IO.MemoryStream())
        {
            using (var writer = new CustomJsonWriter(stream, options))
            {
                JsonSerializer.Serialize(writer, data);
            }
            jsonString = System.Text.Encoding.UTF8.GetString(stream.ToArray());
        }

        // Output the serialized JSON string
        Console.WriteLine(jsonString);
    }
}
