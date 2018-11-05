	import javax.swing.*;
	import java.awt.BorderLayout;
	import java.awt.event.*;
	import java.awt.Dimension;

	public class App extends JFrame
	{
		private static final long serialVersionUID = 1L;
		
		private static JTextArea textArea;
		private static JTextField parameter;
		private static JLabel results;
		
		private int width, height;
		
		private Client client;

		public App(Client client, int width, int height) {
			this.client = client;
			this.width = width;
			this.height = height;
		}




		public void display()
		{
	// Question 1 
			// textArea = new JTextArea("Hello Mr Ghassen CHAABANE !!\n");
			// textArea.setColumns(50);
			// textArea.setRows(10);
			// JScrollPane scroll = new JScrollPane(textArea);
			// add(scroll, BorderLayout.CENTER);

			// JPanel panel = new JPanel();
			// JButton b1 = new JButton("Question?");
			// JButton b2 = new JButton("Answer!");
			// JButton b3 = new JButton("EXIT");

			// panel.add(b1);
			// panel.add(b2);
			// panel.add(b3);
			// add(panel, BorderLayout.NORTH);

			// b1.addActionListener(new ActionListener(){
			// 	public void actionPerformed(ActionEvent e) {
			// 		textArea.append("- How are u ?\n");
			// 	}});
			// b2.addActionListener(new ActionListener(){
			// 	public void actionPerformed(ActionEvent e) {
			// 		textArea.append("- Fine !! Thank you !!\n");
			// 	}});
			// b3.addActionListener(new ActionListener(){
			// 	public void actionPerformed(ActionEvent e) {
			// 		System.exit(0);
			// 	}});

			// setDefaultCloseOperation(EXIT_ON_CLOSE);
			// pack();
			// setVisible(true);


	// Question  2

			// Quit the program when the window is closed
			addWindowListener(new WindowAdapter()
			{
				public void windowClosing(WindowEvent e)
				{
					System.exit(0);
				}
			});

			textArea = new JTextArea("Your results will be shown HERE !!\n");
			textArea.setColumns(50);
			textArea.setRows(10);
			JScrollPane scroll = new JScrollPane(textArea);
			add(scroll, BorderLayout.CENTER);
			
			JMenuBar jMenuBar= new JMenuBar();
			JMenu jAbout = new JMenu("About");
			JMenu jMenu = new JMenu("Menu");
			JToolBar jToolBar = new JToolBar();

		//configuration de jMenu
			
			Action findMediaAction = new Task("FINDMEDIA");
			Action findGroupAction = new Task("FINDGROUP");
			Action listMediaAction = new Task("LISTMEDIAS");
			Action listGroupAction = new Task("LISTGROUPS");
			Action playAction = new Task("PLAY");
			Action closeAction = new Task("EXIT");
			Action aboutusAction = new Task("ABOUT-US");
			Action versionAction = new Task("VERSION");
			jMenu.add(new JMenuItem(listMediaAction));
			jMenu.add(new JMenuItem(listGroupAction));
			jMenu.add(new JMenuItem(findMediaAction));
			jMenu.add(new JMenuItem(findGroupAction));
			jMenu.add(new JMenuItem(playAction));
			jMenu.add(new JMenuItem(closeAction));
			jAbout.add(new JMenuItem(aboutusAction));
			jAbout.add(new JMenuItem(versionAction));
			jMenuBar.add(jMenu);
			jMenuBar.add(jAbout);
			setJMenuBar(jMenuBar);

    	//configuration de jToolBar
			JButton listMediaButton = new JButton("LISTMEDIAS");
			JButton listGroupButton = new JButton("LISTGROUPS");
			JButton findMediaButton = new JButton("FINDMEDIA");
			JButton findGroupButton = new JButton("FINDGROUP");
			JButton playButton = new JButton("PLAY");
			JButton closeButton = new JButton("EXIT");
			parameter = new JTextField("Replace this by the Media/Group Name!!");

			parameter.setColumns(50);
			findMediaButton.setAction(findMediaAction);
			findGroupButton.setAction(findGroupAction);
			listMediaButton.setAction(listMediaAction);
			listGroupButton.setAction(listGroupAction);
			playButton.setAction(playAction);
			closeButton.setAction(closeAction);


			jToolBar.add(listMediaButton);
			jToolBar.add(listGroupButton);
			jToolBar.add(findMediaButton);
			jToolBar.add(findGroupButton);
			jToolBar.add(playButton);
			jToolBar.add(closeButton);
			jToolBar.add(parameter);

			add(jToolBar, BorderLayout.SOUTH);

			
			setDefaultCloseOperation(EXIT_ON_CLOSE);
			pack();
			setVisible(true);
		}

		class Task extends AbstractAction
		{
			private static final long serialVersionUID = 1L;
			String text="";
			public Task(String task){
				super(task);
				text = task;
			}

			@Override
			public void actionPerformed(ActionEvent e)
			{
				String request,response;
				String objectName = parameter.getText();
				if (text == "EXIT")
				{
					textArea.append("\nGood Bye !!\n");
					System.exit(0);
				}
				else if (text == "ABOUT-US") {
					JOptionPane jop1;
					jop1 = new JOptionPane();
					jop1.showMessageDialog(null, "Travail élaboré par l'étudiant CHAABANE Ghassen pour l'unité partagée à Télécom ParisTech INF224 (2018-2019)", "About us", JOptionPane.INFORMATION_MESSAGE);
				}
				else if (text == "VERSION") {
					JOptionPane jop1;
					jop1 = new JOptionPane();
					jop1.showMessageDialog(null, "version : 2.17.11", "Version", JOptionPane.INFORMATION_MESSAGE);
					

				}
				else
				{
					request = text + " " + objectName;
					response = client.send(request);
					textArea.append(response.replace(";","\n"));
					textArea.append("\nJob Done !!\n");
				}
			}
		}



	}

