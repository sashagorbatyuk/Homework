using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Xml.Serialization;

namespace BookSerialization
{
    // Клас Book для серіалізації та десеріалізації
    public class Book
    {
        [JsonPropertyName("BookTitle")]
        [XmlElement("BookTitle")]
        public string Title { get; set; }

        [JsonPropertyName("BookAuthor")]
        [XmlElement("BookAuthor")]
        public string Author { get; set; }

        [JsonPropertyName("BookPrice")]
        [XmlElement("BookPrice")]
        public decimal Price { get; set; }

        [JsonIgnore]
        [XmlIgnore]
        public int InternalId { get; set; }

        // Метод для серіалізації колекції книг у JSON
        public static string SerializeToJson(List<Book> books)
        {
            return JsonSerializer.Serialize(books, new JsonSerializerOptions { WriteIndented = true });
        }

        // Метод для серіалізації колекції книг у XML
        public static string SerializeToXml(List<Book> books)
        {
            var xmlSerializer = new XmlSerializer(typeof(List<Book>));
            using (var stringWriter = new StringWriter())
            {
                xmlSerializer.Serialize(stringWriter, books);
                return stringWriter.ToString();
            }
        }

        // Метод для десеріалізації з JSON
        public static List<Book> DeserializeFromJson(string json)
        {
            return JsonSerializer.Deserialize<List<Book>>(json);
        }

        // Метод для десеріалізації з XML
        public static List<Book> DeserializeFromXml(string xml)
        {
            var xmlSerializer = new XmlSerializer(typeof(List<Book>));
            using (var stringReader = new StringReader(xml))
            {
                return (List<Book>)xmlSerializer.Deserialize(stringReader);
            }
        }
    }

    // Головний клас для виконання програми
    class Program
    {
        static void Main(string[] args)
        {
            // Створення кількох книг
            var books = new List<Book>
            {
                new Book { Title = "C# Programming", Author = "John Doe", Price = 29.99m, InternalId = 1 },
                new Book { Title = "Learn AI", Author = "Jane Smith", Price = 39.99m, InternalId = 2 },
                new Book { Title = "Data Structures", Author = "Alice Johnson", Price = 25.00m, InternalId = 3 }
            };

            // Серіалізація в JSON
            string json = Book.SerializeToJson(books);
            File.WriteAllText("books.json", json);

            // Серіалізація в XML
            string xml = Book.SerializeToXml(books);
            File.WriteAllText("books.xml", xml);

            // Зчитування даних з файлів та десеріалізація з JSON
            string jsonFromFile = File.ReadAllText("books.json");
            List<Book> booksFromJson = Book.DeserializeFromJson(jsonFromFile);
            Console.WriteLine("Deserialized from JSON:");
            foreach (var book in booksFromJson)
            {
                Console.WriteLine($"{book.Title} by {book.Author}, Price: {book.Price}");
            }

            // Зчитування даних з файлів та десеріалізація з XML
            string xmlFromFile = File.ReadAllText("books.xml");
            List<Book> booksFromXml = Book.DeserializeFromXml(xmlFromFile);
            Console.WriteLine("\nDeserialized from XML:");
            foreach (var book in booksFromXml)
            {
                Console.WriteLine($"{book.Title} by {book.Author}, Price: {book.Price}");
            }
        }
    }
}