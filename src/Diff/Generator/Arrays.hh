<?hh //strict

namespace Diff\Generator;

class Arrays<T> implements Generator
{
    private int $max = 0;

    private int $min = 0;

    public function __construct(private array<T> $from, private array<T> $to): void {}

    public function diff(): string
    {

        $problems = $this->findProblems();
        $message = "";

        $message = "";
        for ($key = 0; $key < $this->max; $key++) {
            if ($problems->linearSearch($key) !== -1) {
                $message .= $this->getLineDiff($key);
                continue;
            }
            $message .= $this->getLine($key);
        }

        return $message;
    }

    private function getLine(int $key): string
    {
        return  " " . (string) $this->from[$key] . "\n";
    }

    private function getLineDiff(int $key): string
    {
        $message = "";
        if (array_key_exists($key, $this->from)) {
            $message .= "-" . (string) $this->from[$key] . "\n";
        }

        if (array_key_exists($key, $this->to)) {
            $message .= "+" . (string) $this->to[$key] . "\n";
        }
        return $message;
    }

    private function findProblems(): Vector
    {
        $fromLength = count($this->from);
        $toLength = count($this->to);

        $this->min = min($fromLength, $toLength);
        $this->max = max($fromLength, $toLength);
        $output =  Vector {};

        for ($key = 0; $key < $this->min; $key++) {
            if ($this->from[$key] != $this->to[$key]) {
                $output[] = $key;
            }
        }
        if ($this->min != $this->max) {
            foreach (range($this->min, $this->max - 1) as $key) {
                $output[] = $key;
            }
        }

        return $output;
    }
}
