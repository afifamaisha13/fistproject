import java.util.*;

public class MultistageGraph {
    static class Edge {
        int vertex;
        int weight;
        
        public Edge(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
    }

    public static int multistageForward(List<List<Edge>> graph, int stages, int source, int target) {
        int n = graph.size();
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[source] = 0;

        // Forward pass: Process stages 1 to stages-1
        for (int k = 1; k < stages; k++) {
            for (int u = 0; u < n; u++) {
                if (dp[u] != Integer.MAX_VALUE) {  // Only process reachable nodes
                    for (Edge edge : graph.get(u)) {
                        int v = edge.vertex;
                        int weight = edge.weight;
                        if (dp[v] > dp[u] + weight) {
                            dp[v] = dp[u] + weight;
                        }
                    }
                }
            }
        }

        return dp[target];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of nodes, stages, and edges: ");
        int n = scanner.nextInt();
        int stages = scanner.nextInt();
        int edges = scanner.nextInt();

        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        System.out.println("Enter edges (u v weight) for " + edges + " edges:");
        for (int i = 0; i < edges; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            graph.get(u).add(new Edge(v, w));
        }

        System.out.print("Enter source and target nodes: ");
        int source = scanner.nextInt();
        int target = scanner.nextInt();

        int minCost = multistageForward(graph, stages, source, target);

        if (minCost != Integer.MAX_VALUE)
            System.out.println("Minimum cost from " + source + " to " + target + ": " + minCost);
        else
            System.out.println("No path exists!");

        scanner.close();
    }
}
