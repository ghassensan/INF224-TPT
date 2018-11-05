public class CHAABANE_Ghassen_JAVA_Client
{
	static final String DEFAULT_HOST = "localhost";
	static final int DEFAULT_PORT = 3331;

	static final int WIDTH = 1000;
	static final int HEIGHT = 600;
	
	public static void main(String argv[])
	{
		String host = DEFAULT_HOST;
		int port = DEFAULT_PORT;
		if (argv.length >= 1) host = argv[0];
		if (argv.length >= 2) port = Integer.parseInt(argv[1]);

		Client client = null;
		App app = null;

		try 
		{
			client = new Client(host, port);
			app = new App(client, WIDTH, HEIGHT);
			app.display();
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}
}