import java.io.*;

public class AnimalGame {
	public static void main(String[] args){

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		play(args[0], in, args[1]);
	}

	public static void play(String inputFile, BufferedReader in, String outputFile){
		AnimalTree tree = AnimalTree.readFile(inputFile);

		System.out.println("Welcome to the Animals game!");
		System.out.println();
		System.out.print("Shall we play a game? ");

		try{
			String answer = in.readLine();

			while( affirmative(answer) ){
				tree = playRound(in, tree);

				System.out.println();
				System.out.print("Shall we play a game? ");
				answer = in.readLine();
			}

			System.out.println("Bye!");
		}catch(IOException e){
			throw new RuntimeException(e);
		}

		tree.writeFile(outputFile);
	}

	private static AnimalTree playRound(BufferedReader in, AnimalTree tree){
		try{
			String answer = null;
			AnimalTree root = tree;

			while( !tree.isLeaf() ){
				System.out.print(tree.value() + " ");
				answer = in.readLine();

				if( affirmative(answer) ){
					tree = tree.right();
				}else{
					tree = tree.left();
				}
			}

			System.out.print("Were you thinking of a " + tree.value() + "? ");
			String finalAnswer = in.readLine();

			if( affirmative(finalAnswer) ){
				System.out.println("Great!");
				return root;
			}else{
				System.out.print("Doh! What was the animal? ");
				String animal = in.readLine();
				System.out.print("What question separates " + animal + " from " + tree.value() + "? ");
				String question = in.readLine();
				System.out.print("What is the correct answer for this animal? ");
				String correctAnswer = in.readLine();

				AnimalTree parent = null;

				if( answer != null ){
					parent = (AnimalTree)tree.parent();
				}

				AnimalTree newTree = affirmative(correctAnswer) ?
						new AnimalTree(question, tree, new AnimalTree(animal)) :
						new AnimalTree(question, new AnimalTree(animal), tree);

				if( answer == null){
					return newTree;
				}else{
					if( affirmative(answer) ){
						// we're the right child of our parent
						parent.setRight(newTree);
					}else{
						// we're the left child of our parent
						parent.setLeft(newTree);
					}

					return root;
				}
			}
		}catch(IOException e){
			throw new RuntimeException(e);
		}
	}

	private static boolean affirmative(String answer){
		return answer.equals("y");
	}
}
