import java.util.List;
import java.util.ArrayList;

public class printing {

    public static void printTreeElement(List<Object> node, String prefix) {
        @SuppressWarnings("unchecked")
        List<List<Object>> child = (List<List<Object>>) node.get(1);
        int n = child.size();
        for (int i = 0; i < n; i++) {
            boolean isLastorNot = i == n - 1;
            String newPrefix = prefix + (isLastorNot ? "    " : "│   ");
            System.out.println(prefix + (isLastorNot ? "└── " : "├── ") + child.get(i).get(0));
            printTreeElement(child.get(i), newPrefix);
        }
    }

    public static void main(String[] args) {
        List<Object> elements = new ArrayList<>();
        elements.add("root");
        elements.add(List.of(
                List.of("a", new ArrayList<>()),
                List.of("b", List.of(
                        List.of("p", new ArrayList<>()),
                        List.of("q", List.of(
                                List.of("r", new ArrayList<>()),
                                List.of("s", new ArrayList<>())
                        ))
                )),
                List.of("d", List.of(
                        List.of("e", new ArrayList<>()),
                        List.of("f", List.of(
                                List.of("h", new ArrayList<>()),
                                List.of("i", new ArrayList<>())
                        )),
                        List.of("g", new ArrayList<>())
                ))
        ));

        printTreeElement(elements, "");

    }
}
